import os
import pandas as pd
import matplotlib.pyplot as plt

# load data and process
g_freqs_path = "../g_freqs.csv"

dirname = os.path.dirname(os.path.abspath(__file__))
g_freqs_path = os.path.join(dirname, g_freqs_path)
df = pd.read_csv(g_freqs_path, header=None)

# resistance categories
dha_ppq_aq_triple_resistant = [51, 55]
df["DHA-PPQ, AQ triple-resistant"] = df.iloc[:, dha_ppq_aq_triple_resistant].sum(axis=1)
dha_ppq_lum_triple_resistant = [11, 15]
df["DHA-PPQ, LUM triple-resistant"] = df.iloc[:, dha_ppq_lum_triple_resistant].sum(axis=1)
dha_ppq_double_resistant = [3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63]
df["DHA-PPQ double-resistant"] = df.iloc[:, dha_ppq_double_resistant].sum(axis=1)
asaq_double_resistant = [50, 51, 54, 55]
df["ASAQ double-resistant"] = df.iloc[:, asaq_double_resistant].sum(axis=1)
al_double_resistant = [10, 11, 14, 15]
df["AL double-resistant"] = df.iloc[:, al_double_resistant].sum(axis=1)

print(df[["DHA-PPQ, AQ triple-resistant", "DHA-PPQ, LUM triple-resistant",
            "DHA-PPQ double-resistant", "ASAQ double-resistant", "AL double-resistant"]])

threshold = 0.01
mask = df["DHA-PPQ, AQ triple-resistant"] >= threshold
if mask.any():
    first_occurrence = mask.idxmax()
    print(f"DHA-PPQ + AQ Trip resistance T.01: {first_occurrence}")

# settings
plt.style.use("ggplot")
plt.rcParams["savefig.dpi"] = 300
plt.figure(figsize=(10, 10))

# plot df
plt.plot(df.index, df["DHA-PPQ, AQ triple-resistant"], label="DHA-PPQ, AQ triple-resistant", linewidth=3)
plt.plot(df.index, df["DHA-PPQ, LUM triple-resistant"], label="DHA-PPQ, LUM triple-resistant", linewidth=3)
plt.plot(df.index, df["DHA-PPQ double-resistant"], label="DHA-PPQ double-resistant")
plt.plot(df.index, df["ASAQ double-resistant"], label="ASAQ double-resistant")
plt.plot(df.index, df["AL double-resistant"], label="AL double-resistant")

# settings
plt.xlabel("Transmission cycles", fontsize=12)
plt.ylabel("Frequency (unitless)", fontsize=12)
plt.title("Frequency of resistant clones across generations", fontsize=12)

# grid, legend
plt.grid(True)
plt.legend(loc="upper left")
plt.ylim(0, 1)

plt.show()
