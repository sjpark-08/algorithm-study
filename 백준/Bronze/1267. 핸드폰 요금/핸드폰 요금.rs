use std::{ fs::read, io::stdin };

fn readLine() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let n = readLine().parse::<u32>().unwrap();
    let mut y = 0;
    let mut m = 0;
    let line = readLine();
    let mut parts = line.split_ascii_whitespace();
    for _ in 0..n {
        let minute = parts.next().unwrap().parse::<u32>().unwrap();
        y += ((minute / 30) + 1) * 10;
        m += ((minute / 60) + 1) * 15;
    }

    if y < m {
        println!("Y {}", y);
    } else if y == m {
        println!("Y M {}", y);
    } else {
        println!("M {}", m);
    }
}
