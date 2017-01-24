#!/usr/bin/lua
--[[
--  business
--]]


business = {
        name = nil,
        staff = {}
}

status = {
        OWNER = "Owner",
        NORMAL = "Employee",
        FIRED = "YAH TERMINATED KID!"
}


----


function employee_report()
        employed = 0
        terminated = 0

        report = {}

        for k, v in pairs(business.staff) do
                if v.status ~= status.FIRED then
                        table.insert(report, k .. ", with position: " .. v.position)
                        employed = employed + 1
                else
                        terminated = terminated + 1
                end
        end

        return report, employed, terminated;
end


function staff_add(name, position, status)
        business.staff[name] = {
                position = position,
                status = status
        }
end


function main()
        -- yeee
        business.name = "SCS"

        -- owners
        staff_add("Sean", "Owner", status.OWNER)
        staff_add("Jackie", "Leecher", status.OWNER)

        -- employees
        staff_add("Jake", "Tech", status.NORMAL)
        staff_add("Colby", "Tech", status.NORMAL)
        staff_add("Cameron", "Tech", status.FIRED)
        staff_add("Marty Wall", "Tech", status.FIRED)

        -- fancy report header
        print("Company report for " .. business.name)
        print("=====")

        -- show our report
        report, _, eaugh = employee_report()
        for _, line in pairs(report) do print(line) end

        -- we done yeeee
        print("Yeee, we're at da end... " .. tostring(eaugh) .. " firings today.")
end


-- do this
main()