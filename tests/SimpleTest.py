import CppInPyTemplate as core
import cv2
from concurrent.futures import ThreadPoolExecutor
import time
import numpy as np


def test():
    a = core.mull(2, 5)
    b = core.divid(16, 4)
    print(a)
    print(b)
    core.printEven(12)
    core.printEven(1)
    a = core.CppCalcs(4)
    print(a.multiply(4))
    print(core.list_mull([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5))
    print(core.two_by_two_mull(10, 100))
    a.multiplier = 8
    print(a.multiplier)
    print(a.multiply(10))
    img = a.make_white_image()
    #cv2.imwrite("test.jpg", img)
    print(img)
    print(a.white_image)

    start_time = time.time()
    with ThreadPoolExecutor(4) as ex:
        ex.map(lambda x: core.longLastingFunc(), [None]*4)
    stop_time = time.time() - start_time
    print("Execution took: ", stop_time)

    print("DONE")

if __name__ == "__main__":
    test()
