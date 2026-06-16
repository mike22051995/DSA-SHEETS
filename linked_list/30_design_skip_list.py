import random
from typing import List


class SkipNode:
    def __init__(self, val: int, level: int):
        self.val = val
        self.forward: List[SkipNode] = [None] * (level + 1)


class Skiplist:
    MAX_LEVEL = 16
    P_FACTOR = 0.5

    def __init__(self):
        self.level = 0
        self.head = SkipNode(-1, self.MAX_LEVEL)

    def _random_level(self) -> int:
        lvl = 0
        while lvl < self.MAX_LEVEL and random.random() < self.P_FACTOR:
            lvl += 1
        return lvl

    def search(self, target: int) -> bool:
        curr = self.head
        for i in range(self.level, -1, -1):
            while curr.forward[i] and curr.forward[i].val < target:
                curr = curr.forward[i]

        curr = curr.forward[0]
        return bool(curr and curr.val == target)

    def add(self, num: int) -> None:
        update = [None] * (self.MAX_LEVEL + 1)
        curr = self.head

        for i in range(self.level, -1, -1):
            while curr.forward[i] and curr.forward[i].val < num:
                curr = curr.forward[i]
            update[i] = curr

        lvl = self._random_level()
        if lvl > self.level:
            for i in range(self.level + 1, lvl + 1):
                update[i] = self.head
            self.level = lvl

        node = SkipNode(num, lvl)
        for i in range(lvl + 1):
            node.forward[i] = update[i].forward[i]
            update[i].forward[i] = node

    def erase(self, num: int) -> bool:
        update = [None] * (self.MAX_LEVEL + 1)
        curr = self.head

        for i in range(self.level, -1, -1):
            while curr.forward[i] and curr.forward[i].val < num:
                curr = curr.forward[i]
            update[i] = curr

        curr = curr.forward[0]
        if not curr or curr.val != num:
            return False

        for i in range(self.level + 1):
            if update[i].forward[i] is not curr:
                break
            update[i].forward[i] = curr.forward[i]

        while self.level > 0 and self.head.forward[self.level] is None:
            self.level -= 1

        return True