import sqlite3
import itertools

def main(fname):
    sql_file = '/home/tkhr/etrobo/hrp3/sdk/workspace/etrobocon2021/course_info_generator/sql/drop_and_create_table.sql'

    con = sqlite3.connect(fname)
    cursor = con.cursor()
    
    init_database(cursor, sql_file)
    generator(con, True)
    generator(con, False)
    cursor.close()
    con.commit()
    con.close()

def generator(cursor, is_left=True):
    table_name = 'right_info'
    if is_left:
        table_name = 'left_info'
    sql_template = 'INSERT INTO %s(RED1, RED2, YELLOW1, YELLOW2, BLUE1, BLUE2, GREEN1, GREEN2) VALUES ( %s )'
    for l in itertools.permutations(get_coordinate_list(is_left)):
        sql = sql_template  % (table_name, ','.join(map(lambda x: "'%s'" % x, l)))
        # print(sql)
        cursor.execute(sql)

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

def init_database(cursor, sql_file):
    with open(sql_file) as f:
        sql = f.read()
        cursor.executescript(sql)

if __name__ == '__main__':
    main('all_pattern_course_info.sqlite3')
