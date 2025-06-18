import hashlib
# 读取 key.TEMP 文件的第一行内容
with open('key.TEMP', 'r', encoding='utf-8') as temp_file:
    first_line = temp_file.readline().strip()
# 使用 SHA-256 对密码进行哈希加密
hashed_password = hashlib.sha512(first_line.encode('utf-8')).hexdigest()
# 将哈希值写入 key.DATA 文件
with open('key_hash.TEMP', 'w', encoding='utf-8') as data_file:
    data_file.write(hashed_password)
# print("\nDebug:密码已成功加密并保存到 key_hash.TEMP 文件中。")
