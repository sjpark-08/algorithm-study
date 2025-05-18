use std::cmp::max;
use std::io::stdin;
use std::vec::Vec;

fn read_line() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let line = read_line();
    let mut parts = line.split_ascii_whitespace();
    let m = parts.next().unwrap().parse::<u32>().unwrap();
    let n = parts.next().unwrap().parse::<u32>().unwrap();
    // let mut snacks :[u32; 100001] = [0; 100001];
    let mut snacks = Vec::new();

    let line = read_line();
    let mut parts = line.split_ascii_whitespace();
    let mut left = 1;
    let mut right = 0;
    for _ in 0..n {
        let snack = parts.next().unwrap().parse::<u32>().unwrap();
        right = max(right, snack);
        snacks.push(snack);
    }
    right += 1;

    while left < right {
        let mid = left + right >> 1;
        let mut sum = 0;
        for snack in snacks.iter() {
            sum += snack / mid;
        }
        // println!("{} {} {} {}", left, right, sum, mid);
        if sum >= m {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    println!("{}", left - 1);
}