from collections import defaultdict
from json import load

# EDIT ME
json = '/home/neomi/noi-2023/training/week-5/scores.json'
dest = '/home/neomi/noi-2023/training/week-5/scores.txt'

username = 'lunar_bloom'

include_penalties = True
# -------

def interpret(data):
    scores = defaultdict(float)
    for record in data:
        for hacked_id, gained_points in record['results'].items():
            gained_points = float(gained_points)
            if gained_points > 0 or (gained_points < 0 and include_penalties):
                scores[record['hacker_name']] += gained_points
    
    return scores.items()

def hacked_by(username, data):
    submissions = list()
    for record in data:
        if record['hacker_name'] == username:
            for submission, points in record['results'].items():
                if float(points) > 0:
                    submissions.append(submission)

    return submissions

if __name__ == '__main__':
    with open(json, 'r') as file:
        data = load(file)

    with open(dest, 'w') as file:
        # print(f'The following was hacked by {username}', file=file)
        for submission in interpret(data):
            print(submission, file=file)