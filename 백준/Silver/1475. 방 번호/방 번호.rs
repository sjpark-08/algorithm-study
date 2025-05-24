use std::cmp::{max, min};
use std::io::stdin;

fn read_line() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let line = read_line();
    let mut parts = line.trim().split_ascii_whitespace();
    let mut num = parts.next().unwrap().parse::<u32>().unwrap();

    let mut nums: [u32; 10] = [0; 10];
    while num > 0 {
        let rest = num % 10;
        nums[rest as usize] += 1;
        num /= 10;
    }

    let minv = min(nums[6], nums[9]);
    let maxv = max(nums[6], nums[9]);
    nums[6] = maxv - (maxv - minv) / 2;
    let mut result = 0;
    for i in 0..9 {
        result = max(result, nums[i]);
    }
    println!("{}", result);
}