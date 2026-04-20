import os
import json

problems = list()
practices_to_remove = ["practices/1100/1255B"]
contests_to_remove = ["contests/2134/B"]

def check_solved(path: str) -> list:
    problems = list()
    for root, dirs, files in os.walk(path):
        for file in files:
            if file == "solution.cpp":
                if os.path.exists(os.path.join(root, "output.txt")):
                    with open(os.path.join(root, "output.txt"), 'r') as output_file:
                        output = output_file.read().splitlines()
                        output = [o for o in output if o.strip()]
                    with open(os.path.join(root, "expected.txt"), 'r') as expected_file:
                        expected = expected_file.read().splitlines()
                        expected = [e for e in expected if e.strip()]
                    if output != expected:
                        problems.append(root)
                else:
                    problems.append(root)
    return problems

def remove_solved(problems : list, remove_list : list) -> list:
    for item in remove_list:
        try:
            problems.remove(item)
        except ValueError as e:
            print(e)
    return problems
    
contest_problems = check_solved("contests")
practice_problems = check_solved("practices")

contest_problems = remove_solved(contest_problems, contests_to_remove)
practice_problems = remove_solved(practice_problems, practices_to_remove)

problem_json = { "contest": contest_problems, "practice": practice_problems }
with open("unsolved.json", "w") as file:
    json.dump(problem_json, file, indent=4, sort_keys=True)
