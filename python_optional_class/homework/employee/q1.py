class Employee:
    def __init__(self, name, age, ability=0):
        self.name = name
        self.age = age
        self.ability = 100 - age

    def dowork(self):
        if self.ability >= 5:
            self.ability = self.ability - 5

        else:
            # self.ability = 0
            print('能力值不足！')


    def str(self):
        print('员工姓名:' + self.name, '年龄:' + str(self.age), '能力值:' + str(self.ability))


if __name__ == '__main__':
    employee = Employee('yuan',22)
    employee.str()