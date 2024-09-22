# Problem URL: https://projecteuler.net/problem=19
# ---------------------------------------------------------------------------------
# How many Sundays fell on the first of the month during the 20th century? (1901-2000)

# datetime.date() to handle dates, datetime.timedelta() to do calendar arithemtic (add days)
from datetime import date, timedelta

Start = date(1901, 1, 1)
End = date(2000, 12, 31)
current = Start
sunday_count = 0

# go from the start date to the end date, adding one day each iteration using timedelta()
while (current != End):
    # .day is the day of the month and .weekday() returns an int representing which day of the week it is (0 = monday, 6 = sunday)
    if current.day == 1 and current.weekday() == 6: sunday_count += 1

    # add a day to the current date
    current += timedelta(1)

print(f"{sunday_count} Sundays fell on the first of the month during the 20th century")