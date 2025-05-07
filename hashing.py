def createHashTable():
    size = int(input("Enter the size of hash table: "))
    table = [None] * size
    print(f"Hash table of size {size} created.\n")
    return size, table

def secondaryHashFunction(number, prime):
    return prime - (number % prime)

def insert(size, table, method, count):
    if count >= size:
        print("Hash table is full\n")
        return count

    number = int(input("Enter the number to insert: "))
    name = input("Enter the name: ")
    hashValue = number % size

    if method == "linear":
        while table[hashValue] is not None:
            print("Collision detected (linear)")
            hashValue = (hashValue + 1) % size

    elif method == "double":
        prime = int(input("Enter a prime number less than size: "))
        h2 = secondaryHashFunction(number, prime)
        i = 0
        while table[hashValue] is not None:
            print("Collision detected (double)")
            i += 1
            hashValue = (number % size + i * h2) % size

    table[hashValue] = (number, name)
    print(f"Inserted ({number}, {name}) at index {hashValue}\n")
    return count + 1

def search(method, size, table):
    number = int(input("Enter the number to search: "))
    hashValue = number % size
    comparisons = 0
    prime = 0

    if method == "double":
        prime = int(input("Enter the prime number used during insertion: "))
        h2 = secondaryHashFunction(number, prime)

    while comparisons < size:
        if table[hashValue] is not None and table[hashValue][0] == number:
            print(f"Found at index {hashValue} after {comparisons + 1} comparisons\n")
            return
        comparisons += 1
        if method == "linear":
            hashValue = (hashValue + 1) % size
        elif method == "double":
            hashValue = (number % size + comparisons * h2) % size

    print("Not found in the table.\n")

def display(table, size):
    for i in range(size):
        if table[i] is None:
            status = "empty"
        else:
            status = f"key: {table[i][0]}, value: {table[i][1]}"
        print(f"Slot {i}: {status}")
    print()

def main():
    while True:
        print("Main Menu:")
        print("1. Linear Probing")
        print("2. Double Hashing")
        print("3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 3:
            print("Exiting program.")
            break

        if choice not in [1, 2]:
            print("Invalid choice, try again.\n")
            continue

        method = "linear" if choice == 1 else "double"
        size, table = createHashTable()
        count = 0

        while True:
            print(f"\n{method.capitalize()} Hashing Menu:")
            print("1. Insert")
            print("2. Search")
            print("3. Display")
            print("4. Back to Main Menu")
            op = int(input("Enter operation number: "))

            if op == 1:
                count = insert(size, table, method, count)
            elif op == 2:
                search(method, size, table)
            elif op == 3:
                display(table, size)
            elif op == 4:
                print()
                break
            else:
                print("Invalid operation, try again.\n")

main()
