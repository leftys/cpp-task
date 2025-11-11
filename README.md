# C++ live-coding task

Implement high-performance L2 depth (order book) model in 1 hour. It will be used on SOL-USDT pair with 0.01 tick size and price range of 0-500. We can hard-code those values to speed up implementation. You should implement some function to update quantity on given price (zero quantity = price level is removed), get prices of best bid and ask and get quantity on given price, you can design the interface as you see fit to get good performance.  In the end integrate your code into depth_test.cpp and benchmark its performance. Few nanoseconds per update would be nice. Regarding thread-safety, the model will be updated from a single thread, but may be accessed by several; this is not measured by the benchmark/test though.

Notable performance edge case: it can happen that several price levels need to be updated eg. when bests are $100.01 and $100.02 and we receive update on bid $100.08 to quantity 1. This deletes several ask price levels and creates new bid price level. Order book should always stay consistent meaning bid and ask should never cross.

You can explain your plan, discuss ideas and comment your code as you go to get feedback from us that might help. You can use LLMs to generate parts of the code, but not the entire implementation.
