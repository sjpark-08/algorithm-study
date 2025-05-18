use std::cmp::{max, min};
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
    let n = parts.next().unwrap().parse::<u32>().unwrap();

    if n == 3 {
        println!("0");
    } else {
        // nCn-4
        //  n! / (n - 4)! * 4! / n! => n * (n - 1) * (n - 2) * (n - 3) / 4!
        let ncr = n * (n - 1) * (n - 2) * (n - 3) / 24;
        println!("{}", ncr);
    }
}