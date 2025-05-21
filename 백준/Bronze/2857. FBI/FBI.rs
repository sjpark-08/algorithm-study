use std::cmp::min;
use std::io::stdin;
use std::vec::Vec;

fn read_line() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let mut flag = false;
    for k in 0..5 {
        let line = read_line();
        let chars = line.trim().chars().collect::<Vec<char>>();
        for i in 0..chars.len() {
            if chars[i] == 'F' {
                if &line[i..min(i + 3, chars.len())] == "FBI" {
                    flag = true;
                    print!("{} ", k + 1);
                    break;
                }
            }
        }
    }
    if !flag {
        println!("HE GOT AWAY!");
    }
}