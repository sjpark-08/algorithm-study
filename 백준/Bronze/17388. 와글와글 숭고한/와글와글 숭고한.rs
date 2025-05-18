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
    let s = parts.next().unwrap().parse::<u32>().unwrap();
    let k = parts.next().unwrap().parse::<u32>().unwrap();
    let h = parts.next().unwrap().parse::<u32>().unwrap();

    let min = min(s, min(k, h));

    if s + k + h >= 100 {
        println!("OK");
    } else {
        if s == min {
            println!("Soongsil");
        } else if k == min {
            println!("Korea");
        } else {
            println!("Hanyang");
        }
    }
}