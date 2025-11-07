# 🧩 Binary Search Algorithm
# Author: <Your Name>
# Description: Efficiently search for an element in a sorted array.
# Time Complexity: O(log n)
# Space Complexity: O(1)

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        # Check if the middle element is the target
        if arr[mid] == target:
            return mid

        # If target is greater, ignore left half
        elif arr[mid] < target:
            left = mid + 1

        # If target is smaller, ignore right half
        else:
            right = mid - 1

    # Element not found
    return -1


# 🚀 Example Usage
if __name__ == "__main__":
    arr = [2, 4, 6, 8, 10, 12, 14]
    target = 10
    result = binary_search(arr, target)

    if result != -1:
        print(f"Element {target} found at index {result}")
    else:
        print(f"Element {target} not found in the array.")
