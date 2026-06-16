"""
PROBLEM: Seat Reservation Manager (LeetCode 1845)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap for available seats

DESCRIPTION:
Manage seat reservations 1 to n.
reserve() returns smallest available seat number.
unreserve(seat) marks seat as available again.

EXAMPLE:
SeatManager(5), reserve()->1, reserve()->2, unreserve(1), reserve()->1

TIME COMPLEXITY: O(log n) per operation
SPACE COMPLEXITY: O(n)
"""

import heapq


class SeatManager:
    def __init__(self, n: int) -> None:
        self.available = list(range(1, n + 1))
        heapq.heapify(self.available)

    def reserve(self) -> int:
        return heapq.heappop(self.available)

    def unreserve(self, seat_number: int) -> None:
        heapq.heappush(self.available, seat_number)


if __name__ == "__main__":
    sm = SeatManager(5)
    print(f"reserve() -> {sm.reserve()}")
    print(f"reserve() -> {sm.reserve()}")
    sm.unreserve(1)
    print(f"After unreserve(1), reserve() -> {sm.reserve()}")
    print(f"reserve() -> {sm.reserve()}")
    print(f"reserve() -> {sm.reserve()}")
