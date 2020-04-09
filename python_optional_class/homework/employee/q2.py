from q1 import Employee


class Boss:
    def __init__(self, money, work, flag = 1):
        self.money = money
        self.work = work
        self.employeeList = []
        self.flag = 1  # 1需要雇佣员工,0不需要,2没钱了

    def addEmployee(self, employee):
        if self.money >= 5000:
            self.employeeList.append(employee)
            self.money = self.money - 5000
            print('欢迎新员工')
            print("剩余资金:%d"%self.money)
        else:
            print('money不足，无法雇佣新员工！')
            self.flag = 2

# 创建Boss类对象，默认执行雇佣3个员工，年龄分别为30,40,50，
    def init_employee(self):
        new_employee1 = Employee('张三', 30)
        new_employee1.str()
        self.addEmployee(new_employee1)
        new_employee2 = Employee('李四', 40)
        new_employee2.str()
        self.addEmployee(new_employee2)
        new_employee3 = Employee('王五', 50)
        new_employee3.str()
        self.addEmployee(new_employee3)

    def startWork(self):
        for employee in self.employeeList:
            while employee.ability != 0:
                employee.dowork()
                self.work = self.work - 5
                print(employee.name + "剩余能力值：%d" % employee.ability)
                print("剩余工作量：%d" % self.work)
                if self.work <= 0:
                    self.flag = 0
                    print("工作完成!")
                    self.endWork()
                    break
        if self.flag == 2:
            print("你的公司倒闭了")

        if self.flag == 1:
            print("员工不足，请雇佣新员工")
            print("剩余工作量：%d" % self.work)
            choose = str(input("\n是否雇佣新员工(y/n):"))
            if choose == 'y':
                new_name = str(input("请输入新员工姓名："))
                new_age = int(input("请输入新员工年龄："))
                new_Emploee = Employee(new_name, new_age)
                self.addEmployee(new_Emploee)
                self.startWork()
            if choose == 'n':
                print("我决定放弃治疗")


    def endWork(self):
        print("员工表：")
        for i in self.employeeList:
            print("员工姓名："+i.name )
            print('能力值：%d'%i.ability)


if __name__ == '__main__':
    # boss = Boss(100000,100) # 顺利完成
    boss = Boss(100000,1000) #员工不足
    # boss = Boss(10000,200) #money不足
    boss.init_employee()
    boss.startWork()
    boss.endWork()