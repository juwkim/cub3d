import os

# 폴더 경로 설정
folder_path = 'bonus/source'

# 폴더 안의 파일 목록 가져오기
folder_list = os.listdir(folder_path)

# 이름 변경 규칙 설정
new_suffix = '_bonus'

# 파일 이름 변경
for old_name in folder_list:
    # 파일인지 확인
	folder = os.path.join(folder_path, old_name)
	if os.path.isdir(folder):
		file_list = os.listdir(folder)
		for file in file_list:
			file = os.path.join(folder, file)
			filename, file_extension = os.path.splitext(file)
			new_name = f"{filename}{new_suffix}{file_extension}"
			os.rename(file, new_name)
			print(f"Renamed: {file} -> {new_name}")
