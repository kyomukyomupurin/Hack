import filecmp
import subprocess
import sys
from pathlib import Path
import argparse


def compile_cpp(filename: str):
    print('compiling {}...'.format(Path(filename).name))
    subprocess.run(['g++', '-std=c++17', '-O2',
                    filename, '-o', Path(filename).stem])


def broken_line():
    print('------------------------------------------------\n')


def challenge():
    subprocess.run('./gen', stdout=open('./gen.txt', 'w'))
    sol_out = subprocess.run(
        './sol', check=True, stdin=open('./gen.txt', 'r'), stdout=subprocess.PIPE).stdout
    stupid_out = subprocess.run(
        './stupid', check=True, stdin=open('./gen.txt', 'r'), stdout=subprocess.PIPE).stdout

    if sol_out != stupid_out:
        print('[test {:<3}] : WA'.format(i + 1))
        print('Hackd!\n')
        print('input')
        broken_line()
        with open('./gen.txt', 'r') as hack_case:
            lines = hack_case.readlines()
            for line in lines:
                print(line)
        broken_line()
        print('expected output')
        broken_line()
        print(stupid_out.decode('utf-8'))
        broken_line()
        print('your output')
        broken_line()
        print(sol_out.decode('utf-8'))
        broken_line()
        exit(0)
    else:
        print("[test {:<3}] : AC".format(i + 1))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Input a trial number!")
        exit(0)

    parser = argparse.ArgumentParser()
    parser.add_argument('try_count', help='number of trial')
    args = parser.parse_args()
    try_count = int(args.try_count)

    compile_cpp('./gen.cc')
    compile_cpp('./sol.cc')
    compile_cpp('./stupid.cc')
    print('running...')
    for i in range(try_count):
        challenge()
