#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
(if the format is not this one, the line must be skipped)
After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics:
    - Total file size: File size: <total size>
    - Number of lines by status code in ascending order:
      possible status codes: 200, 301, 400, 401, 403, 404, 405, 500
      (if a status code doesn’t appear or is not an integer, don’t print it)
"""

import sys
import signal


def print_stats(total_size, status_counts):
    """
    Print the statistics of the log parsing.
    
    Args:
        total_size (int): The total file size.
        status_counts (dict): The count of each status code.
    """
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


def signal_handler(sig, frame):
    """
    Handle the keyboard interrupt signal and print the stats before exiting.
    
    Args:
        sig (int): The signal number.
        frame (frame object): The current stack frame.
    """
    print_stats(total_size, status_counts)
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

total_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) < 10:
            continue

        try:
            ip = parts[0]
            date = parts[3] + " " + parts[4]
            method = parts[5][1:]
            url = parts[6]
            protocol = parts[7][:-1]
            status_code = int(parts[8])
            file_size = int(parts[9])

            if method != "GET" or url != "/projects/260" or protocol != "HTTP/1.1":
                continue

            total_size += file_size
            if status_code in status_counts:
                status_counts[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        except (ValueError, IndexError):
            continue

except KeyboardInterrupt:
    print_stats(total_size, status_counts)
    sys.exit(0)

