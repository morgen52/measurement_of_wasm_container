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
    // // creat a file and write "hello"
    // let mut file = File::create("hello.txt").unwrap();
    // file.write_all(b"hello").unwrap();
    // // read the file
    // let mut file = File::open("hello.txt").unwrap();
    // let mut contents = String::new();
    // file.read_to_string(&mut contents).unwrap();
    // println!("contents: {}", contents);

    let iteration = 100;
    for _i in 0..iteration {
      let mut start = std::time::Instant::now();
      create_file("tmp.txt", "This is in a file");
      println!("create file: {:?}", start.elapsed());

      start = std::time::Instant::now();
      println!("File content is {}", read_file("tmp.txt"));
      println!("read file: {:?}", start.elapsed());

      start = std::time::Instant::now();
      del_file("tmp.txt");
      println!("delete file: {:?}", start.elapsed());
    }
    
}
