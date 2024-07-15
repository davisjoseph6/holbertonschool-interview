#!/usr/bin/python3
"""
Interview
"""

def validUTF8(data):
    """
    Interviewe
    """
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    # Masks to check the significant bits of a byte
    mask1 = 1 << 7
    mask2 = 1 << 6

    # Iterate over each integer in the data
    for byte in data:
        # Get the 8 least significant bits of the byte
        byte = byte & 0xFF

        # If this is the start of a new UTF-8 character
        if num_bytes == 0:
            # Count the number of leading 1s in the first byte
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask = mask >> 1

            # If no leading 1s, it's a 1-byte character
            if num_bytes == 0:
                continue

            # A character should be between 2 and 4 bytes
            if num_bytes == 1 or num_bytes > 4:
                return False

        else:
            # If we r in the middle of a UTF-8 character,check 4 continuation
            if not (byte & mask1 and not (byte & mask2)):
                return False

        # Decrease the number of bytes left for the current UTF-8 character
        num_bytes -= 1

    # If we end with num_bytes not being 0, it means there are not enough
    return num_bytes == 0
