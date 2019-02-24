import time, random
import matplotlib.pyplot as plt

def sort(lists):
	length = len(lists)

	for i in range(length - 1):
		forgetmin = lists[i]
		forgeti = i

		for j in range(i + 1, length):
			if forgetmin > lists[j]:
				forgetmin = lists[j]
				forgeti = j

		if i != forgeti:
			lists[i], lists[forgeti] = lists[forgeti], lists[i]


def main():
	a = 100
	b = 200
	times = 1000

	timeMeas = []
	maxsize = b
	lists = [[random.randint(10, 1000) for _ in range(maxsize)] for _ in range(times)]

	for size in range(a, maxsize + 1):
		startTime = time.time()

		for lst in lists:
			sort(lst[:size])

		endTime = time.time()
		timeMeas.append(endTime - startTime)

	x = [i for i in range(a, b + 1)]
	y = timeMeas
	plt.plot(x, y)
	plt.savefig('result.png')

if __name__ == '__main__':
	main()