# 🔍 Linear Search Algorithm
# Author: Siri Reddy
# Description: Searches for a target element in an array by checking each element one by one.
# Time Complexity: O(n)
# Space Complexity: O(1)

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


if __name__ == "__main__":
    arr = [10, 20, 80, 30, 60, 50, 110, 100, 130]
    target = 60
    result = linear_search(arr, target)
    print(f"Element {target} found at index {result}" if result != -1 else "Element not found")
