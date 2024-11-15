# Making Change

## Description

The **Making Change** project involves creating a function `makeChange` that determines the minimum number of coins required to make a given amount. This function takes a list of coin denominations and a target total amount, returning the fewest coins needed. If it is not possible to meet the total using the given coins, the function returns `-1`.

The implementation uses **Dynamic Programming** to ensure efficiency and correctness.

## Requirements

- Python 3.4.3
- PEP 8 style guide compliance (version 1.7.x)
- Executable scripts

## Prototype

```python
def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.

    Args:
        coins (list): A list of the values of the coins in your possession.
        total (int): The target amount to meet.

    Returns:
        int: The fewest number of coins needed to meet the total, or -1 if
             the total cannot be met with the given coins.
    """
Usage
Example 1:
Input:

python
Copy code
coins = [1, 2, 5]
total = 11
Output:

python
Copy code
3  # (5 + 5 + 1)
Example 2:
Input:

python
Copy code
coins = [2]
total = 3
Output:

python
Copy code
-1  # Not possible to make 3 with only 2-value coins
Example 3:
Input:

python
Copy code
coins = [1, 2, 25]
total = 37
Output:

python
Copy code
7  # (25 + 2 + 2 + 2 + 2 + 2 + 2)
File Structure
0-making_change.py: Contains the makeChange function implementation.
main_11.py: Script for testing the makeChange function with sample inputs.
How to Run
Clone the repository:

bash
Copy code
git clone <repository_url>
cd making_change
Ensure the scripts are executable:

bash
Copy code
chmod +x 0-making_change.py main_11.py
Run the test script:

bash
Copy code
./main_11.py
Algorithm
The implementation uses a Dynamic Programming approach:

A dp array is initialized to track the minimum number of coins required for each amount up to the target total.
Each coin value is iterated, updating the dp array for amounts that can include that coin.
If the target total cannot be reached, the function returns -1.
Complexity
Time Complexity: 
𝑂
(
𝑛
⋅
𝑚
)
O(n⋅m), where 
𝑛
n is the total and 
𝑚
m is the number of coin denominations.
Space Complexity: 
𝑂
(
𝑛
)
O(n), where 
𝑛
n is the total.
Example Outputs
Running the provided main_11.py:

bash
Copy code
$ ./main_11.py
3
-1
7
-1
Author
Davis Joseph
License
This project is open source and free to use.
