from pathlib import Path

def cpu_work():
    x = 1.1
    for i in range(10000000):
        x = x*x

def io_work():
    file_path = Path("tempfile.txt")
    with file_path.open("w") as fp:
        fp.write("Test line\n")

    with file_path.open("r") as fp:
        for i in range(100000):
            fp.readline()
            fp.seek(0, 0)

    file_path.unlink()

def f1():
    cpu_work()

def f2():
    io_work()

def mainfunc():
    for i in range(10):
        f1()
        #f2()

if __name__ == "__main__":
    mainfunc()
