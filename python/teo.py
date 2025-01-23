import time

def countdown(seconds):
    while seconds:
        mins, secs = divmod(seconds, 60)
        time_format = '{:02d}:{:02d}'.format(mins, secs)
        print(time_format, end='\r')
        time.sleep(1)
        seconds -= 1
    print("Time's up!")

def main():
    seconds = int(input("Enter the time in seconds: "))
    countdown(seconds)

if __name__ == "__main__":
    main()
