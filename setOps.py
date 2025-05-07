set1=[]
set2=[]

def addElement(s,element):
    if element not in s:
        s.append(element)
    return s

def removeElement(s,element):
    if element in s:
        s.remove(element)
    else:
        print(f"Element {element} not present in set")
    return s

def containsElement(s,element):  
        return element in s

def getSize(s):
    cnt=0
    for _ in s:
          cnt+=1
    return cnt   

def display(s1,s2):
    print("set Element : ", s1)
    print("set Element : ", s2)


def setUnion(s1,s2):
    res = s1.copy()
    for element in s2:
        if element not in res:
            res.append(element)
    return res

def setIntersection(s1,s2):
    res = []
    for element in s1:
        if element in s2:
            res.append(element)
    return res

def setDiff(s1,s2):
    res = []
    for element in s1:
        if element not in s2:
            res.append(element)
    return res

def subSet(s1,s2):
    for element in s1:
        if element not in s2:
            return False
    return True


def main():
    global set1,set2
    while True:
        print("\n===== Set ADT Operations =====")
        print("1. Add element to Set 1")
        print("2. Add element to Set 2")
        print("3. Remove element from Set 1")
        print("4. Remove element from Set 2")
        print("5. Check if element is in Set 1")
        print("6. Check if element is in Set 2")
        print("7. Display Set 1 and set 2")
        #print("8. Display Set 2")
        print("9. Union of Set 1 and Set 2")
        print("10. Intersection of Set 1 and Set 2")
        print("11. Difference (Set1 - Set2)")
        print("12. Check if Set 1 is subset of Set 2")
        print("13. Get size of Set 1")
        print("14. Get size of Set 2")
        print("15. Exit")

        choice = input("Enter your choice ")
        if choice == '1':
            element = input("Enter element to add to Set 1: ")
            set1 = addElement(set1, element)

        elif choice == '2':
            element = input("Enter element to add to Set 2: ")
            set2 = addElement(set2, element)

        elif choice == '3':
            element = input("Enter element to remove from Set 1: ")
            set1 = removeElement(set1, element)

        elif choice == '4':
            element = input("Enter element to remove from Set 2: ")
            set2 = removeElement(set2, element)

        elif choice == '5':
            element = input("Enter element to check in Set 1: ")
            print(f"Element {element} is {'present' if containsElement(set1, element) else 'not present'} in Set 1")

        elif choice == '6':
            element = input("Enter element to check in Set 2: ")
            print(f"Element {element} is {'present' if containsElement(set2, element) else 'not present'} in Set 2")

        elif choice == '7':
            display(set1,set2)
        # elif choice == '8':
        #     display(set2)

        elif choice == '9':
            result = setUnion(set1, set2)
            print("Union of Set 1 and Set 2:", result)

        elif choice == '10':
            result = setIntersection(set1, set2)
            print("Intersection of Set 1 and Set 2:", result)

        elif choice == '11':
            result = setDiff(set1, set2)
            print("Difference (Set1 - Set2):", result)
        elif choice == '12':

            print("Set 1 is", "a subset" if subSet(set1, set2) else "not a subset", "of Set 2")

        elif choice == '13':
            print("Size of Set 1:", getSize(set1))

        elif choice == '14':
            print("Size of Set 2:", getSize(set2))

        elif choice == '15':
            print("Exiting program...")
            
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 15.")

main()