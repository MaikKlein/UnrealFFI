//LogTemp: Warning: DLL Address 36125840
//LogTemp: Warning: Log Address 20738422
use std::ffi::CString;
use std::os::raw::c_char;
#[no_mangle]
pub extern "system" fn rust_log(log: fn(s: *const c_char, foo: u32)) -> u32 {
    let s = CString::new("String from Rust").unwrap();
    println!("RUST");
    (log)(s.as_ptr(), 70);
    1
}
