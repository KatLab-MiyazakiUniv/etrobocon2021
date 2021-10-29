import itertools

def main(fname, is_left):
    with open(fname, mode='w') as fp:
        generator(fp, is_left=is_left)


def generator(fp, is_left=True):
    csv_header = 'course_info,access_counter,first_access_time_milli_sec,last_access_time_milli_sec\n'
    fp.write(csv_header)
    for l in itertools.permutations(get_coordinate_list(is_left)):
        course_info = ''.join(l)
        csv_line = '%s,%s,%s,%s\n' % (course_info, '00000000', '0', '0')
        fp.write(csv_line)


def get_coordinate_list(is_left=True):
    """
    ブロックを配置可能な座標情報を取得する。

    Parameters
    ----------
    is_left : bool, default True
    """
    if is_left:
        return 'EMBKDRGP'
    return 'HJCLAQFS'

if __name__ == '__main__':
    main('course-info-l.csv', True)
    main('course-info-r.csv', False)
