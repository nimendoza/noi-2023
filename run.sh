#!/bin/bash

set -e

home=$(pwd)

path=$1

if [ -z "$path" ]; then
    echo "Usage: $0 <path> <command>"
    echo "Example: $0 flip-a test 100 200"
    echo "       <path> - path to the directory containing the following file/s:"
    echo "                - solution.cpp"
    echo "                - solution.naive.cpp (optional)"
    echo "                - generate.cpp (optional)"
    echo "                - input.txt (optional)"
    echo "       <command> - command to run"
    echo "                   - <nothing> - (requires solution.cpp)"
    echo "                               - runs the solution.cpp file"
    echo "                   - run - (requires solution.cpp)"
    echo "                         - runs the solution.cpp file"
    echo "                   - run-in - (requires solution.cpp and input.txt)"
    echo "                            - runs the solution.cpp file with input.txt as input"
    echo "                   - run-out - (requires solution.cpp)"
    echo "                             - runs the solution.cpp file and outputs to output.txt"
    echo "                   - naive - (requires solution.naive.cpp)"
    echo "                           - runs the solution.naive.cpp file"
    echo "                   - naive-in - (requires solution.naive.cpp and input.txt)"
    echo "                              - runs the solution.naive.cpp file with input.txt as input"
    echo "                   - naive-out - (requires solution.naive.cpp)"
    echo "                               - runs the solution.naive.cpp file and outputs to output.naive.txt"
    echo "                   - in-out - (requires solution.cpp, solution.naive.cpp, and input.txt)"
    echo "                            - runs the solution.cpp and solution.naive.cpp files with input.txt as input and outputs to output.txt and output.naive.txt"
    echo "                            - also compares the outputs"
    echo "                   - test <amount> <...args> - (requires generate.cpp, solution.cpp, and solution.naive.cpp)"
    echo "                                             - runs the following <amount> times, passing <...args> to generate.exe:"
    echo "                                             - runs the generate.cpp file to generate input.txt to feed into the respective solutions"
    echo "                                             - runs the solution.cpp and solution.naive.cpp files to compare the outputs"
    exit 1
fi

if [ ! -d "$path" ]; then
    echo "Directory $path does not exist"
    exit 1
fi

cd $path

command=$2

if [ -z $command ]; then
    command="run"
fi

if [ $command == "run" ]; then
    g++ solution.cpp -o output.exe
    ./output.exe
elif [ $command == "run-in" ]; then
    g++ solution.cpp -o output.exe
    ./output.exe < input.txt
elif [ $command == "run-out" ]; then
    g++ solution.cpp -o output.exe
    ./output.exe > output.txt
elif [ $command == "naive" ]; then
    g++ solution.naive.cpp -o output.naive.exe
    ./output.naive.exe
elif [ $command == "naive-in" ]; then
    g++ solution.naive.cpp -o output.naive.exe
    ./output.naive.exe < input.txt
elif [ $command == "naive-out" ]; then
    g++ solution.naive.cpp -o output.naive.exe
    ./output.naive.exe > output.naive.txt
elif [ $command == "in-out" ]; then
    g++ solution.cpp -o output.exe
    g++ solution.naive.cpp -o output.naive.exe
    ./output.exe < input.txt > output.txt
    ./output.naive.exe < input.txt > output.naive.txt
    diff output.txt output.naive.txt
elif [ $command == "test" ]; then
    amount=$3

    if [ -z $amount ]; then
        amount=1
    fi

    g++ generate.cpp -o generate.exe
    g++ solution.cpp -o output.exe
    g++ solution.naive.cpp -o output.naive.exe

    # $i doubly serves as both our counter and our seed
    for ((i = 1; i <= $amount; i++)); do
        echo "    Test $i"
        ./generate.exe $i ${@:4} > input.txt
        ./output.exe < input.txt > output.txt
        ./output.naive.exe < input.txt > output.naive.txt
        diff output.txt output.naive.txt
    done
elif [ $command == "test-against" ]; then
    person=$3
    amount=$4

    if [ -z $amount ]; then
        amount=1
    fi

    g++ generate.cpp -o generate.exe
    g++ solution.$person.cpp -o output.$person.exe
    g++ solution.naive.cpp -o output.naive.exe
    g++ solution.cpp -o output.exe

    read -p "Constaints for brute force testing: " brute

    echo "Checking if Neomi's solution is correct..."
    # $i doubly serves as both our counter and our seed
    for ((i = 1; i <= $amount; i++)); do
        echo "    Test $i"
        ./generate.exe $i $brute > input.txt
        ./output.exe < input.txt > output.txt
        ./output.naive.exe < input.txt > output.naive.txt
        diff output.txt output.naive.txt
    done

    echo "Checking if $person's solution is correct..."
    for ((i = 1; i <= $amount; i++)); do
        echo "    Test $i"
        ./generate.exe $i $brute > input.txt
        eval "./output.$person.exe < input.txt > output.$person.txt"
        ./output.naive.exe < input.txt > output.naive.txt
        diff output.$person.txt output.naive.txt
    done

    read -p "Constraints for larger testings: " large

    echo "Testing Neomi's against $person's solution..."
    for ((i = 1; i <= $amount; i++)); do
        echo "    Test $i"
        ./generate.exe $i $large > input.txt
        ./output.exe < input.txt > output.txt
        eval "./output.$person.exe < input.txt > output.$person.txt"
        diff output.txt output.$person.txt
    done
elif [ $command == "stress" ]; then
    amount=$3

    g++ generate.cpp -o generate.exe
    g++ solution.naive.cpp -o output.naive.exe

    for ((i = 1; i <= amount; i++)); do
        ./generate.exe $i ${@:4} > input.txt
        ./output.naive.exe < input.txt > output.naive.txt
    done
else
    echo "Invalid command: $command"
    exit 1
fi

cd $home
