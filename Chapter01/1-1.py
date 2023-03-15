import numpy as np

def main():
    
    house = np.array(['A','c','e','r','Y','F','R','z','G','a'])
    
    house[1], house[2], house[5], house[7], house[8] = '', '', '', '', ''
    
    house[1] = house[3]
    house[3] = ""
    
    house[2] = house[6]
    house[6] = ""
    
    house[3] = house[9]
    house[9] = ""
    
    print(house)
    
if __name__ == "__main__":
    main()