import sys
import time


def menu():
    print("Main Menu")
    print("1. Rupee Coin Change by Brute Force")
    print("2. Rupee Coin Change by Greedy Algoritm")


def bruteForce(coins, sum):
    if sum == 0:
        return 0

    else:
        result = sys.maxsize
        for coin in coins:
            if (coin <= sum):
                result = min(result, bruteForce(coins, sum - coin) + 1)

    return result


def greedy(exchange):
    coin1, coin2, coin3, coin4 = [0] * 4
    while exchange != 0:
        if exchange >= 1000:
            exchange -= 1000
            coin1 += 1

        elif 1000 > exchange >= 500:
            exchange -= 500
            coin2 += 1

        elif 500 > exchange >= 200:
            exchange -= 200
            coin3 += 1

        elif 200 > exchange >= 100:
            exchange -= 100
            coin4 += 1

    print("Coin 1000: {}".format(coin1))
    print("Coin 500: {}".format(coin2))
    print("Coin 200: {}".format(coin3))
    print("Coin 100: {}".format(coin4))


coins = [100, 200, 500, 1000]
sum = int(input("Enter the ammount: "))
menu()
val = input("Enter your choice: ")
while val != '0':
    if val == '1':
        print("Coins: ", coins)
        print("Sum: ", sum)
        begin = time.perf_counter()
        print("Minimum Coins: {}".format(bruteForce(coins, sum)))
        end = time.perf_counter()
        print("Time execution =>", end - begin)
    elif val == '2':
        begin = time.perf_counter()
        greedy(sum)
        end = time.perf_counter()
        print("Time execution =>", end - begin)

    menu()
    val = input("Enter your choice")