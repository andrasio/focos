extern crate libc;

extern {
    fn Focos_Crear(focos: &mut libc::c_ushort);
    fn Focos_PrenderTodos();
    fn Focos_Prender(para_foco: libc::c_int);
    fn Focos_Apagar(para_foco: libc::c_int);
}

fn main() {
    let mut focos = 0u16;
    
    unsafe { 
        Focos_Crear(&mut focos);
    }

    println!("Focos: {}", focos);
    println!("Prendiendo focos y quedará {}...", 0x180);

    unsafe {
        Focos_Prender(9);
        Focos_Prender(8);
    }

    println!("Quedó {}.", focos);
    println!("Apagando focos...");

    unsafe {
        Focos_Apagar(9);
        Focos_Apagar(8);
    }

    println!("Focos: {}", focos);
}
