use chrono::prelude::*;

fn main() {
    let mut local_time = Local::now().format("%M:%S%.6f").to_string();
    println!("start completed current time:{}", local_time);

    let iter_times = 10000;
    let sum = 0;
    for _i in 0..iter_times {
        println!("Hello, world! {}", sum);
    }
    println!("sum: {}", sum);
    local_time = Local::now().format("%M:%S%.6f").to_string();
    println!("end current time:{}", local_time);
}
