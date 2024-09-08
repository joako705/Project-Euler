# Problem URL: https://projecteuler.net/problem=19
# ---------------------------------------------------------------
# How many Sundays fell on the first of the month during the twentieth century? (1901-2000)

from datetime import date, timedelta

start = date(1901, 1, 1)
end = date(2000, 12, 31)
current = start
sunday_count = 0

while (current != end):
    # .day is the day of the month and .weekday() returns an int representing which day of the week it is (0 = monday, 6 = sunday)
    if current.day == 1 and current.weekday() == 6: sunday_count += 1

    # add a day to the current date
    current += timedelta(1)

print(f"{sunday_count} sundays fell on the first of the month during the 20th century.")