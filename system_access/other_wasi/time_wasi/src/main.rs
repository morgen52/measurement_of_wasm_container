use chrono::prelude::*;

fn main() {
    let mut local_time = Local::now().format("%M:%S%.6f").to_string();
    println!("start completed current time:{}", local_time);

    let iter_times = 10000;
    let mut sum = 0;
    let mut start;
    for _i in 0..iter_times {
        // time::Instant::now();
        start = std::time::Instant::now();
        sum += start.elapsed().as_micros();
    }
    println!("sum: {}", sum);
    local_time = Local::now().format("%M:%S%.6f").to_string();
    println!("end current time:{}", local_time);
}
