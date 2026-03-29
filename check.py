import os
import json

problems = list()

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
    
contest_problems = check_solved("contests")
practice_problems = check_solved("practices")

problem_json = { "contest": contest_problems, "practice": practice_problems }
with open("unsolved.json", "w") as file:
    json.dump(problem_json, file, indent=4, sort_keys=True)
