import os
import pandas as pd
import matplotlib.pyplot as plt

# load data and process
mean_fitness_path = "../mean_fitness.csv"

dirname = os.path.dirname(os.path.abspath(__file__))
g_freqs_path = os.path.join(dirname, mean_fitness_path)
df = pd.read_csv(mean_fitness_path, header=None)
df = df.iloc[1:]

print(df)

# settings
plt.style.use("ggplot")
plt.figure(figsize=(10, 10))
plt.rcParams["savefig.dpi"] = 300

# plot df
plt.plot(df.iloc[:])

# setting labels
plt.xlabel("Transmission cycles", fontsize=12)
plt.ylabel("Mean fitness (unitless)", fontsize=12)
plt.title("Mean fitness of infected hosts across generations", fontsize=12)

# grid
plt.grid(True)

plt.show()
