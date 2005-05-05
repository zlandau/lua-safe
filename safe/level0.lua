
require "common"

local testcase = lunit.TestCase("Level 0 Testcases")

function testcase.test_taint()
    local var = 5
    lunit.assert_false(istainted(var))
    var = taint(var)
    lunit.assert_true(istainted(var))

    lunit.assert_false(istainted(1+2))

    local exp = taint(1) + 2 + 3
    lunit.assert_true(istainted(exp))

    exp = 1 + 2 + taint(3)
    lunit.assert_true(istainted(exp))

    local exp = 1 + 2 / 3 * 4^taint(5) + -6
    lunit.assert_true(istainted(exp))

    local exp = taint("one") .. "two"
    lunit.assert_true(istainted(exp))
end

local ret = lunit.run()
os.exit(ret)
