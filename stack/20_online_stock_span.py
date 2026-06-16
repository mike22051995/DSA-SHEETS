"""
PROBLEM: Online Stock Span (LeetCode 901)
DIFFICULTY: Medium
PATTERN: Monotonic Stack for Stock Span

DESCRIPTION:
Design an algorithm that collects daily price quotes for some stock and returns 
the span of that stock's price for the current day.
The span of the stock's price today is defined as the maximum number of consecutive 
days (starting from today and going backward) for which the stock price was less than 
or equal to today's price.

INPUT: 
StockSpanner stockSpanner = new StockSpanner()
stockSpanner.next(100); # return 1
stockSpanner.next(80);  # return 1
stockSpanner.next(60);  # return 1
stockSpanner.next(70);  # return 2
stockSpanner.next(60);  # return 1
stockSpanner.next(75);  # return 4
stockSpanner.next(85);  # return 6

TIME COMPLEXITY: O(1) amortized for next()
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic decreasing stack storing pairs of (price, span).
For each new price, pop all smaller or equal prices and accumulate their spans.
This gives us the span for current price efficiently.
"""



class StockSpanner:
    def __init__(self):
        self.stack = []  # (price, span)

    def next(self, price: int) -> int:
        span = 1
        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]
        self.stack.append((price, span))
        return span


if __name__ == "__main__":
    stockSpanner = StockSpanner()
    prices = [100, 80, 60, 70, 60, 75, 85]
    print("Price -> Span")
    print("-------------")
    for price in prices:
        span = stockSpanner.next(price)
        print(f"{price} -> {span}")

    print("\nAnother example:")
    stockSpanner2 = StockSpanner()
    prices2 = [31, 41, 48, 59, 79]
    print("Price -> Span")
    print("-------------")
    for price in prices2:
        span = stockSpanner2.next(price)
        print(f"{price} -> {span}")
