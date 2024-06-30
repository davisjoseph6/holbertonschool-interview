# Log Parsing

## Explanation:-
1. Signal Handling: The script uses signal.signal to catch a KeyboardInterrupt (CTRL + C) and print the statistics before exiting.
2. Initialization: It initializes total_size to track the sum of file sizes and status_counts dictionary to count occurrences of each status code.
3. Reading and Parsing: The script reads from stdin line by line, splits each line, and validates its format.
4. Metrics Calculation: For each valid line, it updates the total_size and the respective status code count.
5. Periodic Output: Every 10 lines, it prints the current statistics.
6. Handling Keyboard Interrupt: When a KeyboardInterrupt is caught, the current statistics are printed, and the script exits.

## Usage:
To use this script, save it to a file, e.g., 0-stats.py, make it executable (chmod +x 0-stats.py), and run it while piping input from another script or file that generates the log entries in the specified format.
