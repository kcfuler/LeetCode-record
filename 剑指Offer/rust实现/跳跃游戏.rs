fn can_jump(nums: Vec<i32>) -> bool {
    let mut max_distance = 0;

    for (i, &num) in nums.iter().enumerate() {
        if i > max_distance {
            return false;
        }

        max_distance = max_distance.max(i + num as usize);
    }
}

fn main() {
    let nums = vec![2, 3, 1, 1, 4];
    println!("{}", can_jump(nums));
}
