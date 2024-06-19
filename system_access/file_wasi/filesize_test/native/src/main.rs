use std::fs;
use std::fs::File;
use std::io::{Write, Read};

pub fn create_file(path: &str, content: &str) {
  let mut output = File::create(path).unwrap();
  output.write_all(content.as_bytes()).unwrap();
}

pub fn read_file(path: &str) -> String {
  let mut f = File::open(path).unwrap();
  let mut s = String::new();
  match f.read_to_string(&mut s) {
    Ok(_) => s,
    Err(e) => e.to_string(),
  }
}

pub fn del_file(path: &str) {
  fs::remove_file(path).expect("Unable to delete");
}

fn main() {
    let iteration = 100;
    let mut start;
    
    // increasing file size
    let mut file_size = 1;
    let size_index = 30; // 2^0=1B - 2^30 = 512MiB
    let mut content = String::new();
    content.push_str("a"); // 1 byte

    // write the result to a file
    let mut output = File::create("result.json").unwrap();
    output.write_all("{\n".as_bytes()).unwrap();

    for j in 0..size_index {
        let mut create_time = 0;
        let mut read_time = 0;
        let mut del_time = 0;
        // println!("File size is {}", file_size);

        for _i in 0..iteration {
            // println!("Iteration {}", _i);
            start = std::time::Instant::now();
            create_file("tmp.txt", &content);
            create_time += start.elapsed().as_nanos();
    
            start = std::time::Instant::now();
            // println!("File content is {}", read_file("./tmp.txt"));
            read_file("./tmp.txt");
            // println!("read file: {:?}", start.elapsed());
            read_time += start.elapsed().as_nanos();

            start = std::time::Instant::now();
            del_file("tmp.txt");
            // println!("delete file: {:?}", start.elapsed());
            del_time += start.elapsed().as_nanos();
        }

        // println!("create file: {} ns", create_time / iteration);
        // println!("read file: {} ns", read_time / iteration);
        // println!("delete file: {} ns", del_time / iteration);

        output.write_all(format!("\t\"{}\": {{\n", file_size).as_bytes()).unwrap();
        output.write_all(format!("\t\t\"create file\": {},\n", create_time / iteration).as_bytes()).unwrap();
        output.write_all(format!("\t\t\"read file\": {},\n", read_time / iteration).as_bytes()).unwrap();
        output.write_all(format!("\t\t\"delete file\": {}\n", del_time / iteration).as_bytes()).unwrap();
        if j == size_index - 1 {
            output.write_all(format!("\t}}\n").as_bytes()).unwrap();
        } else {
            output.write_all(format!("\t}},\n").as_bytes()).unwrap();
        }
        // output.write_all(format!("\t}},\n").as_bytes()).unwrap();

        content = content.repeat(2);
        file_size *= 2;
    }

    output.write_all("}\n".as_bytes()).unwrap();

    //print the result
    println!("{}", read_file("./result.json"));
    
}
