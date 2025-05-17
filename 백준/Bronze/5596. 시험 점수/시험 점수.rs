use std::io::stdin;

fn read_line() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    // let n = read_line().parse::<u32>().unwrap();
    let mut sum1 = 0;
    let mut sum2 = 0;
    let line = read_line();
    let mut parts = line.split_ascii_whitespace();
    for _ in 0..4 {
        let score = parts.next().unwrap().parse::<u32>().unwrap();
        sum1 += score;
    }

    let line = read_line();
    let mut parts = line.split_ascii_whitespace();
    for _ in 0..4 {
        let score = parts.next().unwrap().parse::<u32>().unwrap();
        sum2 += score;
    }

    if sum1 > sum2 {
        println!("{}", sum1);
    } else {
        println!("{}", sum2);
    }

}
