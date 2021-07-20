class task(object):
    def __init__(self, start_time, end_time):
        self.start = start_time
        self. end = end_time

def get_end(task1: task):
    return task1.end

def max_task(task_list: list):
    task_list = sorted(task_list, key=get_end)
    last_task = task_list[0]
    count = 1

    for i in task_list:
        if i.start >=  last_task.end:
            count+=1
            last_task= i

    return count

if __name__ == "__main__":
    n = int(input())
    task_list = []
    i = 0
    while i<n:
        start, end = list(map(int,input().split()))
        task1 = task(start, end)
        task_list.append(task1)
        i+=1
    
    print(max_task(task_list))
   

