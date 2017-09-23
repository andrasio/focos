extern crate gcc;

fn main() {
  gcc::Build::new().include("include/Focos")
                   .file("src/Focos/Focos.c")
                   .compile("libfocos.a");
}
