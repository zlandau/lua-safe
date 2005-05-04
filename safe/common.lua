
require "lunit.lua"

function safety_check(func)
    return lunit.assert_error_match("safety violation", func)
end
