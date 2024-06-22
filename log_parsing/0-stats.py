#!/usr/bin/python3
"""
placeholder
"""

import sys
import signal


def print_stats(total_size, status_counts):
    """
    placeholder
    """
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


def signal_handler(sig, frame):
    """
    placeholder
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
    """
    placeholder
    """
    print_stats(total_size, status_counts)
    sys.exit(0)
