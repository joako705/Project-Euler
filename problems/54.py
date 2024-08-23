#the "54_poker.txt" file has 1000 random hands dealt to two players. how many hands does player 1 win?

from enum import Enum
with open("C:/Users/jpere/Documents/code/Project-Euler/helpers/54_poker.txt") as file:
    text = file.readlines()

class rank(Enum):
    HIGH_CARD = 0
    ONE_PAIR = 1
    TWO_PAIRS = 2
    THREE_OF_A_KIND = 3
    STRAIGHT = 4
    FLUSH = 5
    FULL_HOUSE = 6
    FOUR_OF_A_KIND = 7
    STRAIGHT_FLUSH = 8
    ROYAL_FLUSH = 9

def read_card(card):
    value = 0
    suit = ""

    if (card[0] == 'T'): value = 10
    elif (card[0] == 'J'): value = 11
    elif (card[0] == 'Q'): value = 12
    elif (card[0] == 'K'): value = 13
    elif (card[0] == 'A'): value = 14
    else: value = int(card[0])

    if (card[1] == 'C'): suit = "Clubs"
    elif (card[1] == 'S'): suit = "Spades"
    elif (card[1] == 'H'): suit = "Hearts"
    elif (card[1] == 'D'): suit = "Diamonds"

    return [value, suit]

def score_hand(hand):
    values = []
    suits = []

    for i in range(5):
        values.append(hand[i][0])
        suits.append(hand[i][1])
    
    values.sort()
    
    is_flush = (len(set(suits)) == 1)
    is_straight = (values == list(range(values[0], values[0] + 5)) or values == [14, 5, 4, 3, 2,])
    
    if is_flush and values == [10, 11, 12, 13, 14]:
        return rank.ROYAL_FLUSH
    elif is_flush and is_straight:
        return rank.STRAIGHT_FLUSH
    elif is_flush:
        return rank.FLUSH
    elif is_straight:
        return rank.STRAIGHT

    value_counts = {value: values.count(value) for value in values}
    counts = sorted(value_counts.values(), reverse=True)
    
    if counts == [4, 1]:
        return rank.FOUR_OF_A_KIND
    elif counts == [3, 2]:
        return rank.FULL_HOUSE
    elif counts == [3, 1, 1]:
        return rank.THREE_OF_A_KIND
    elif counts == [2, 2, 1]:
        return rank.TWO_PAIRS
    elif counts == [2, 1, 1, 1]:
        return rank.ONE_PAIR
    else:
        return rank.HIGH_CARD

def tiebreaker(p1, p2):
    p1 = sorted(p1, reverse = True)
    p2 = sorted(p2, reverse = True)

    for i in range(5):
        if (p1[i] > p2[i]): return True
        elif (p1[i] == p2[i]): continue
        else: return False

def find_wins():
    wins = 0

    for line in text:
        cards = line.strip().split(" ")
        p1_cards = cards[:5]
        p2_cards = cards[5:]

        p1_values = []
        p2_values = []

        p1_values = [read_card(card) for card in p1_cards]
        p2_values = [read_card(card) for card in p2_cards]
        
        p1_rank = score_hand(p1_values)
        p2_rank = score_hand(p2_values)

        if p1_rank.value > p2_rank.value: wins += 1 
        elif p1_rank.value == p2_rank.value:
            if tiebreaker(p1_values, p2_values): wins += 1
        
    return wins

print(find_wins())