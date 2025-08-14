import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Read the results
df = pd.read_csv('sorting_results.csv')

# Create the plot
plt.figure(figsize=(12, 8))
sns.set_style("whitegrid")

# Create line plot
for algorithm in df['Algorithm'].unique():
    data = df[df['Algorithm'] == algorithm]
    plt.plot(data['Size'], data['Time(ms)'], marker='o', label=algorithm, linewidth=2, markersize=8)

plt.xscale('log')  # Use log scale for x-axis
plt.yscale('log')  # Use log scale for y-axis

# Customize the plot
plt.title('Sorting Algorithm Performance Comparison', fontsize=16, pad=20)
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Average Time (ms)', fontsize=12)
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', fontsize=10)
plt.grid(True, which="both", ls="-", alpha=0.2)

# Adjust layout to prevent label cutoff
plt.tight_layout()

# Save the plot
plt.savefig('sorting_comparison.png', dpi=300, bbox_inches='tight')
plt.close()
