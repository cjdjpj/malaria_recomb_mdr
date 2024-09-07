import os
import pandas as pd
import matplotlib.pyplot as plt

# load data
sensitivity_analysis_path = "../sensitivity_analysis.csv"

dirname = os.path.dirname(os.path.abspath(__file__))
sensitivity_analysis_path = os.path.join(dirname, sensitivity_analysis_path)
df = pd.read_csv(sensitivity_analysis_path)

# get mean and error
means = df.mean()
errors = df.sem()

# settings
plt.rcParams["savefig.dpi"] = 300
plt.style.use("ggplot")
plt.figure(figsize=(10, 10))
plt.title("Single drug + WT start: R0 vs Time to max fitness clone fixation")
plt.xlabel("R0")
plt.ylabel("Time to max fitness clone fixation (# of generations)")
plt.xticks(rotation=45)
plt.grid(True)
plt.tight_layout()

# error bars
plt.errorbar(means.index, means, yerr=errors, fmt="-o", capsize=5)

plt.show()
