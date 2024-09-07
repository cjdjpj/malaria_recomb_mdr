import os
import csv

g_freqs_path = "../g_freqs.csv"

dirname = os.path.dirname(os.path.abspath(__file__))
g_freqs_path = os.path.join(dirname, g_freqs_path)

with open(g_freqs_path, newline="") as csvfile:
    reader = csv.reader(csvfile)
    df = list(reader)

last_row = df[-1]

print("Surviving clones (at last gen):")
for clone_num, frequency in enumerate(last_row):
    if float(frequency) > 0.005:
        print(f"Clone {clone_num}: {frequency}")
